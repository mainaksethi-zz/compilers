#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <set>
#include <map>
using namespace std;


set<string> addfirstnt(string nt,set<string> &terminal,set<string> &nonterminal,vector< vector< vector <string> > > &production,map <string,set <string> > &first)
{
	//cout<<"cjghj"<<endl;
	int i;
	set<string> ret;
	if(!first[nt].empty())
	{
		return first[nt];
	}
	string eps="EPSILON";
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
					ret.insert(*it);
				}
				//ret.insert(addfirstnt(st,terminal,nonterminal,production,first).begin(),addfirstnt(st,terminal,nonterminal,production,first).end());
				//cout<<"aya3"<<endl;
			}
			else
			{
				//cout<<"aya"<<endl;
				ret.insert(first[st].begin(),first[st].end());
			}	
			if(first[st].find(eps)==first[st].end())
			{
				break;
			}
		}
	}
	//cout<<"aya"<<endl;
	first[nt]=ret;
	return ret;
}


void input(vector< vector< vector <string> > > &production,ifstream &file)
{
	string line;
	int n,m,index1=0,index2=0;
	while(getline(file,line))
	{
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
		for (int j = 0; j < production[i].size(); ++j)
		{
			addfirstnt(nt,terminal,nonterminal,production,first);
		}
	}
	return ;
}
void makefollow(set<string> &terminal,set<string> &nonterminal,vector< vector< vector <string> > > &production,map <string,set <string> > &first,map <string,set <string> > &follow)
{
	int i;
	string eps="EPSILON";
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
	string eps="EPSILON";
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
	follow[production[0][0][0]].insert(dollar);
	for(set<string>::iterator it=nonterminal.begin();it!=nonterminal.end();it++)
	{
		string nt = *it;
		makefollow(terminal,nonterminal,production,first,follow);
	}
	makefollow2(terminal,nonterminal,production,first,follow);
	return ;
}

void addtable(set<string> &terminal,set<string> &nonterminal,vector< vector< vector <string> > > &production,map <string,set <string> > &first,map <string,set <string> > &follow,map <string, map <string, int> > &table)
{
	string eps="EPSILON";
	set<string>::iterator it,it2;
	for (int i = 0; i < production.size(); ++i)
	{
		string index1=production[i][0][0];
		for (int j = 0; j < production[i].size(); ++j)
		{
			if(production[i][j][0]==eps)
			{
				for(it=follow[index1].begin();it!=follow[index1].end();it++)
				{
					if(*it!=eps)
					{
						table[index1][*it]=j;
					}
				}	
			}
			else
			{
				for(it=first[production[i][j][0]].begin();it!=first[production[i][j][0]].end();it++)
				{
					if(*it!=eps)
					{
						table[index1][*it]=j;
					}
				}
			}
		}
	}
	return ;
}
int main()
{
	vector< vector< vector <string> > > production;
	set<string> terminal,nonterminal;
	map <string,set <string> > first,follow;
	map <string, map <string, int> > table;
	ifstream file;
	file.open("input.txt");
 	input(production,file);
 	/*for (int i = 0; i < production.size(); ++i)
	{
		for (int j = 0; j < production[i].size(); ++j)
		{
			for (int k = 0; k < production[i][j].size(); ++k)
			{
				cout<<production[i][j][k]<<i<<","<<j<<","<<k<<","<<endl;
			}
		}
	}*/
 	file.close();
 	addnonterminal(nonterminal,production);
 	addterminal(terminal,nonterminal,production);
	addfirst(terminal,nonterminal,production,first);
	addfollow(terminal,nonterminal,production,first,follow);
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
	// 	set<string>::iterator it,it2;
	// cout<<"N-T	";
	// for (it2 = terminal.begin(); it2 !=terminal.end(); ++it2)
	// {
	// 	cout<<*it2<<"	";
	// }
	// cout<<endl;
	// for (it = nonterminal.begin(); it !=nonterminal.end(); it++)
	// {
	// 	cout<<*it<<"	";
	// 	for (it2 = terminal.begin(); it2 !=terminal.end(); ++it2)
	// 	{
	// 		cout<<table[*it][*it2]<<"	";
	// 	}
	// 	cout<<endl;
	// }
	return 0;
}