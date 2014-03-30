#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <set>
#include <map>
#include "defines.h"

using namespace std;

extern int yylex();


vector<string> getproduction(vector<vector<vector <string> > > &production,string top,int prodno)
{
	for(int i=0;i<production.size();i++)
	{
		if(production[i][0][0]==top)
		{
			return production[i][prodno];
		}
	}

}

set<string> addfirstnt(string nt,set<string> &terminal,  set<string> &nonterminal,   vector< vector< vector <string> > > &production,   map <string,set <string> > &first)
{
	int i;
	set<string> ret;
	if(!first[nt].empty())
	{
		return first[nt];
	}
	string eps="E";
	for(i=0;i<production.size();i++)
	{
		if(production[i][0][0]==nt)
		{
			//cout<<production[i][0][0]<<endl;
			break;
		}
	}
	for(int j=1;j<production[i].size();j++)
	{
		for (int k = 0; k < production[i][j].size(); ++k)
		{
			set<string> star;
			//cout<<"aya2"<<endl;
			//cout<<production[i][j][k]<<endl;
			string st=production[i][j][k];
			if(terminal.find(st)==terminal.end())
			{
				//cout<<"aya4"<<endl;
				set<string> star=addfirstnt(st,terminal,nonterminal,production,first);
				for (set<string>::iterator it = star.begin(); it !=star.end() ; it++)
				{
					if(*it!="E")
					{
						ret.insert(*it);
					}
				}
				//ret.insert(addfirstnt(st,terminal,nonterminal,production,first).begin(),addfirstnt(st,terminal,nonterminal,production,first).end());
				//cout<<"aya3"<<endl;
			}
			else
			{
				//cout<<"aya"<<endl;
				ret.insert(st);
			}	
			if(first[st].find(eps)==first[st].end())
			{
				break;
			}
		}
	}
	bool flag=true;
	for(int j=1;j<production[i].size();j++)
	{
		flag=true;
		for (int k = 0; k < production[i][j].size(); ++k)
		{
			if(first[production[i][j][k]].find(eps)==first[production[i][j][k]].end())
			{
				//cout << "epsilon not found in first of " << production[i][j][k] << endl <<endl;
				flag=false;
			}
		}
		if(flag==true)
		{
			cout << "epsilon inserted in first of " << production[i][0][0] << endl <<endl;
			ret.insert(eps);
		}
	}
	//cout<<"aya"<<endl;
	first[nt]=ret;
	return ret;
}

void addfirst(set<string> &terminal,set<string> &nonterminal,vector< vector< vector <string> > > &production,map <string,set <string> > &first)
{
	set<string>::iterator it;
	for(it=terminal.begin();it!=terminal.end();it++)
	{
		set<string> st;
		st.insert(*it);
		first[*it]=st;
	}
	for(int i=0;i<production.size();i++)
	{
		set<string> st;
		string nt = production[i][0][0];
		for (int j = 1; j < production[i].size(); ++j)
		{
			addfirstnt(nt,terminal,nonterminal,production,first);
		}
	}
	return ;
}



void input(vector< vector< vector <string> > > &production,ifstream &file)
{
	string line;
	int n,m,index1=0,index2=0;
	while(getline(file,line))
	{
		//cout<<"line ayi"<<endl;
		production.resize(index1+1);
		index2=0;
		int i=0,j=0;
		stringstream ss(line);
		string token;
		ss >> token;
		production[index1].resize(index2+1);
		production[index1][index2].push_back(token);
		ss >> token;
		index2++;
		production[index1].resize(index2+1);
		while(ss >> token)
		{
			if(token=="|")
			{
				index2++;
				production[index1].resize(index2+1);
			}
			else
			{
				production[index1][index2].push_back(token);
			}
		}
		index1++;
	}
	return ;
}

void addnonterminal(set<string> &nonterminal,vector< vector< vector <string> > > &production)
{
	for (int i = 0; i < production.size(); ++i)
	{
		nonterminal.insert(production[i][0][0]);
	}
	return ;
}

void addterminal(set<string> &terminal,set<string> &nonterminal,vector< vector< vector <string> > >&production)
{
	string dollar="$";
	for (int i = 0; i < production.size(); ++i)
	{
		for (int j = 0; j < production[i].size(); ++j)
		{
			for (int k = 0; k < production[i][j].size(); ++k)
			{
				if((nonterminal.find(production[i][j][k])==nonterminal.end()) && (terminal.find(production[i][j][k])==terminal.end()))
				{
					terminal.insert(production[i][j][k]);
				}
			}
		}
	}
	terminal.insert(dollar);
	return ;
}

void makefollow(set<string> &terminal,set<string> &nonterminal,vector< vector< vector <string> > > &production,map <string,set <string> > &first,map <string,set <string> > &follow)
{
	//cout<<"make follow"<<endl;
	int i;
	string eps="E";
	set<string>::iterator it;
	for(int i=0;i<production.size();i++)
	{
		for(int j=1;j<production[i].size();j++)
		{
			for(int k=0;k<production[i][j].size();k++)
			{
				string nt=production[i][j][k];
				int z=k+1;
				while(z<production[i][j].size())
				{
					for(it=first[production[i][j][z]].begin();it!=first[production[i][j][z]].end();it++)
					{
						if(*it!=eps)
						{
							follow[nt].insert(*it);
						}
					}
					if(first[production[i][j][z]].find(eps)==first[production[i][j][z]].end())
					{
						break;
					}
					z++;
				}
			}
		}
	}
}

void makefollow2(set<string> &terminal,set<string> &nonterminal,vector< vector< vector <string> > > &production,map <string,set <string> > &first,map <string,set <string> > &follow)
{
	int i;
	string eps="E";
	set<string>::iterator it;
	bool change =true;
	while(change==true)
	{
		change = false;
		for(int i=0;i<production.size();i++)
		{
			string nt=production[i][0][0];
			for(int j=1;j<production[i].size();j++)
			{
				int z = (production[i][j].size()-1);
				while(z>=0)
				{
					if(production[i][j][z]==eps)
					{
						break;
					}
					for(it=follow[nt].begin();it!=follow[nt].end();it++)
					{
						if((follow[production[i][j][z]].find(*it)==follow[production[i][j][z]].end()) && (*it!=eps))
						{
							change =true;
							follow[production[i][j][z]].insert(*it);
						}
					}
					if(first[production[i][j][z]].find(eps)==first[production[i][j][z]].end())
					{
						break;
					}
					z--;
				}
			}
		}
	}
	return ;
}

void addfollow(set<string> &terminal,set<string> &nonterminal,vector< vector< vector <string> > > &production,map <string,set <string> > &first,map <string,set <string> > &follow)
{
	set<string>::iterator it2,it;
	string dollar="$";
	//cout<<"idhar"<<endl;
	cout<<production[0][0][0]<<endl;
	follow[production[0][0][0]].insert(dollar);
	//cout<<"idhar2"<<endl;
	for(set<string>::iterator it=nonterminal.begin();it!=nonterminal.end();it++)
	{
		string nt = *it;
		makefollow(terminal,nonterminal,production,first,follow);
	}
	//cout<<"aya-follow1"<<endl;
	makefollow2(terminal,nonterminal,production,first,follow);
	return ;
}

set<string> firstofproduction(vector<string> st, map <string,set <string> > &first)
{
	string eps="E";
	set<string> ret;	
	set<string>::iterator it; 
	int i;
	for(i=0;i<st.size();i++)
	{
		if(first[st[i]].find(eps)==first[st[i]].end())  //if epsilon not found
		{
			for(it=first[st[i]].begin();it!=first[st[i]].end();it++)
			{
				ret.insert(*it);
			}
			break;
		}
		else
		{
			for(it=first[st[i]].begin();it!=first[st[i]].end();it++)
			{
				if(*it!=eps)
				{
					ret.insert(*it);
				}
			}	
		}
	}
	if(i==st.size())
	{
		//cout << "mainak" << endl;
		ret.insert(eps);
	}
	return ret;
}

void addtable(set<string> &terminal,set<string> &nonterminal,vector< vector< vector <string> > > &production,map <string,set <string> > &first,map <string,set <string> > &follow,map <string, map <string, int> > &table)
{
	string eps="E";
	set<string>::iterator it,it2;
	map <string,set <string> >::iterator it3;
	set<string> st;
	for (int i = 0; i < production.size(); ++i)
	{
		string index1=production[i][0][0];
		for (int j = 1; j < production[i].size(); ++j)
		{
			st=firstofproduction(production[i][j],first);
			cout << "printing first for production " << index1 << " --> ";
			for(int k=0;k<production[i][j].size();k++)
			{
				cout << production[i][j][k];
			}
			cout << endl;
			for(it=st.begin();it!=st.end();it++)
			{
				cout << *it << ", ";
				if (*it != eps)
				{
					table[index1][*it]=j;
				}
				
			}
			cout << endl;

			if(st.find(eps)!=st.end())
			{
				for(it=follow[index1].begin();it!=follow[index1].end();it++)
				{
					table[index1][*it]=j;
				}
			}
		}
	}

	return ;
}

void makeReverseMap(map<int,string> &m)
{
	 m[LB] = "{";
	 m[RB] = "}";
	 m[LP] = "(";
	 m[RP] = ")";
	 m[COMMA] = ",";
	 m[SEMI] = ";";
	 m[PLUS] = "+";
	 m[SUB] = "-";
	 m[MUL] = "*";
	 m[DIV] = "/";
	 m[EQ] = "=";
	 m[IF] = "IF";
	 m[WHILE] = "WHILE";
	 m[DO] = "DO";
	 m[FOR] = "FOR";
	 m[RETURN] = "RETURN";
	 m[CONTINUE] = "CONTINUE";
	 m[BREAK] = "BREAK";
	 m[NUM] = "NUM";
	 m[ID] = "ID";
	 m[DATA_TYPE] = "DATA_TYPE";
	 m[0] = "$";
}

int index(vector< vector< vector <string> > > &production, string NT)
{
	for (int i = 0; i < production.size(); ++i)
	{
		if (production[i][0][0] == NT)
		{
			return i;
		}
	}

	return -1;
}

void rmvLR_OneLevel(set<string> &terminal,set<string> &nonterminal,vector< vector< vector <string> > > &production)
{

	int iniSize = production.size();
	for (int i = 0; i < iniSize; ++i)
	{
		for (int j = 1; j < production[i].size(); ++j)
		{

			if(production[i][0][0] == production[i][j][0]) //if A -> AM type thing occur
			{

				vector< vector<string> > q;
				string NT =  production[i][0][0];
				string NT_P = NT + "_prime";


				vector<string> r;
				r.push_back(NT_P);
				q.push_back(r);
				//nonterminal.insert(NT_P);

				for (int k = 1; k < production[i].size(); ++k)
				{
					if (production[i][k][0] != NT) //if it is does not start with NT
					{
						production[i][k].push_back(NT_P);
					}
					else
					{
						production[i][k].push_back(NT_P );
						production[i][k].erase(production[i][k].begin());
						q.push_back(production[i][k]);
						production[i].erase(production[i].begin() + k);
						k--;
					}
				}

				vector<string> r2;
				string eps = "E";
				r2.push_back(eps);
				if(terminal.find(eps) == terminal.end())
				{
					terminal.insert(eps);
				}
				q.push_back(r2);
				production.push_back(q);
				break;
			}
		}
	}
	
}


void rmvLR_MultiLevel(set<string> &terminal,set<string> &nonterminal,vector< vector< vector <string> > > &production)
{
	for (int i = 0; i < production.size(); ++i)
	{
		string CurNT = production[i][0][0];
		int iniSize = production[i].size();
		for (int j = 1; j < iniSize; ++j)
		{
			string prefixProd = production[i][j][0];
			if (nonterminal.find(prefixProd) != nonterminal.end())  // if prefix of this production is NT 
			{
				int prevProdIndex = index(production,prefixProd);

				if (prevProdIndex < index(production, CurNT)) //if index of prefix of production is less than current NT
				{
					for (int k = 1; k < production[prevProdIndex].size(); ++k) 
					{
						vector<string> newProd;
						for (int m = 0; m < production[prevProdIndex][k].size(); ++m)
						{
							newProd.push_back(production[prevProdIndex][k][m]);
						}
						for (int n = 1; n < production[i][j].size(); ++n)
						{
							newProd.push_back(production[i][j][n]);
						}

						production[i].push_back(newProd);
						
					}
					production[i].erase(production[i].begin() + j);
					j--; iniSize--;
				}
			}

			
		}

		for (int t = 1; t < production[i].size(); ++t)
		{
			if(nonterminal.find(production[i][t][0]) != nonterminal.end())  // if prefix of this production is NT 
			{
				if (index(production,production[i][t][0]) < index(production, production[i][0][0]))
				{
					i--;
					break;
				}
			}
		}
			
	}

	rmvLR_OneLevel(terminal,nonterminal,production);
}

void printstack(std::vector<string> &v){
	cout<<endl;
	for (int i = 0; i < v.size(); ++i)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	vector< vector< vector <string> > > production;
	set<string> terminal,nonterminal;
	map <string,set <string> > first,follow;
	map <string, map <string, int> > table;
	ifstream file;
	file.open("grammarLTST.txt");
 	input(production,file);
 	cout<<production.size()<<endl;
 // 	for (int i = 0; i < production.size(); ++i)
	// {
	// 	for (int j = 0; j < production[i].size(); ++j)
	// 	{
	// 		for (int k = 0; k < production[i][j].size(); ++k)
	// 		{
	// 			cout<<production[i][j][k]<<i<<","<<j<<","<<k<<","<<endl;
	// 		}
	// 	}
	// }
 	file.close();
 	ofstream fout;
	fout.open("output.txt");
	fout<<"-------------GRAMMAR"<<endl;
	for (int i = 0; i < production.size(); ++i)
	{
		fout << production[i][0][0] << " : " ;
		for (int j = 1; j < production[i].size(); ++j)
		{
			for (int n = 0; n < production[i][j].size(); ++n)
			{
				fout << production[i][j][n] << " " ;
			}

			fout << "| ";
		}

		fout <<endl;
	}
 	//cout<<"aya1"<<endl;
 	addnonterminal(nonterminal,production);
 	//cout<<"aya2"<<endl;
 	addterminal(terminal,nonterminal,production);
 	rmvLR_MultiLevel(terminal,nonterminal,production);
	//cout<<"aya3"<<endl;
	addfirst(terminal,nonterminal,production,first);
	//cout<<"aya4"<<endl;
	map <string,set <string> >::iterator it2;
	set<string>::iterator it3;
	// cout << "\n\n\n\n\n-----------------FIRST" << endl;
	// for (it2 = first.begin(); it2 != first.end(); it2++)
	// {
	// 	cout << it2->first << " : ";
	// 	set<string> st = it2->second;
	// 	for (it3 = st.begin(); it3 != st.end(); it3++)
	// 	{
	// 		cout << *it3 << " ";
	// 	}
	// 	cout << endl;
	// }
	addfollow(terminal,nonterminal,production,first,follow);
	//print follow
	// cout << "\n\n\n\n---------------------FOLLOW\n\n\n\n\n" << endl;
	// for (it2 = follow.begin(); it2 != follow.end(); it2++)
	// {
	// 	cout << it2->first << " : ";
	// 	set<string> st = it2->second;
	// 	for (it3 = st.begin(); it3 != st.end(); it3++)
	// 	{
	// 		cout << *it3 << " ";
	// 	}
	// 	cout << endl;
	// }
	// cout<<"aya5"<<endl;
	addtable(terminal,nonterminal,production,first,follow,table);
	//print first follow
	//	set<string>::iterator it,it2;
	// for (it = terminal.begin(); it !=terminal.end(); it++)
	// {
	// 	cout<<*it<<"-";
	// 	for (it2 = follow[*it].begin(); it2 !=follow[*it].end(); ++it2)
	// 	{
	// 		cout<<*it2<<",";
	// 	}
	// 	cout<<endl;
	// }
	// for (it = nonterminal.begin(); it !=nonterminal.end(); it++)
	// {
	// 	cout<<*it<<"-";
	// 	for (it2 = follow[*it].begin(); it2 !=follow[*it].end(); ++it2)
	// 	{
	// 		cout<<*it2<<",";
	// 	}
	// 	cout<<endl;
	// }
	//print-table
	map <string, map <string, int> >::iterator it;
	map<string , int>::iterator it1;
	//fout<<"N-T	";
	// cout << "\n\n\n\n\n---------------------LL1" << endl;
	// for (it = table.begin(); it != table.end(); it++)
	// {
	// 	for (it1 = (it->second).begin(); it1 != (it->second).end(); it1++)
	// 	{
	// 		cout << it->first << ":" << it1->first << "\t";
	// 		int i;
	// 		for(i=0;i<production.size();i++)
	// 		{
	// 			if(production[i][0][0]==(it->first))
	// 			{
	// 				break;
	// 			}
	// 		}
	// 		int j=table[it->first][it1->first];
	// 		//cout<<production[i][j].size();
	// 		for(int k=0;k<production[i][j].size();k++)
	// 		{
	// 			cout<<production[i][j][k];
	// 		}
	// 		cout << endl;
	// 	}
	// }
	map<int, string> reverseMap;
	makeReverseMap(reverseMap);
	string start=production[0][0][0];
	vector<string> parsestack;
	parsestack.push_back("$");
	parsestack.push_back(start);
	printstack(parsestack);
	int lexeme = yylex();
	string ltp = reverseMap[lexeme];
	while(1)
	{
		cout<<"lexeme"<<" "<<ltp<<endl;
		string top = parsestack[parsestack.size() - 1];
		cout<<"top="<<top<<endl;
		parsestack.pop_back();
		if (!lexeme)
		{
			cout << "Successfully Parsed" << endl;
			return 0;
		}
		if(nonterminal.find(top)!=nonterminal.end())
		{
			if(table[top][ltp]==0)
			{
				string str1=top;
				string str2=ltp;
				cout<<table[str1][str2]<<endl;
				cout<<"Parsing error"<<endl;
				return 0;
			}
			int prodno = table[top][ltp];
			vector<string> prod = getproduction(production,top,prodno);
			for (int i = prod.size() - 1; i >= 0; i--)
			{
				if(prod[i] != "E")
				{
					parsestack.push_back(prod[i]);
				}
			}
 		}
		else
		{
			if(top!=ltp)
			{
				cout<<"Parsing error"<<endl;
				return 0;
			}
			lexeme = yylex();
			ltp = reverseMap[lexeme];
		}
		printstack(parsestack);
		cout<<endl;
	}
	return 0;
}