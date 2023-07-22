#include <bits/stdc++.h>
using namespace std;
#define sz(x) (int)x.size()
#define pb(x) push_back(x)

void LRU(vector<int> pages)
{
	vector<vector<int>> ans(3, vector<int>(sz(pages), -1));

	bool flag, flag1;
	int hit = 0;
	vector<int> lru;
	if (sz(pages) >= 1)
	{
		ans[0][0] = pages[0];
		lru.pb(pages[0]);

		for (int i = 1; i < sz(pages); i++)
		{

			// copy prev page frames

			flag = false;
			for (int j = 0; j < 3; j++)
			{
				ans[j][i] = ans[j][i - 1];
			}

			for (int j = 0; j < 3; j++)
			{
				if (ans[j][i] == pages[i])
				{
					flag = true;
					hit++;
					lru.pb(pages[i]);
					break;
				}
			}

			if (!flag)
			{
				flag1 = false;
				for (int j = 0; j < 3; j++)
				{
					if (ans[j][i] == -1)
					{
						ans[j][i] = pages[i];
						lru.pb(pages[i]);
						flag1 = true;
						break;
					}
				}

				if (!flag1)
				{
					bool i0 = false, i1 = false, i2 = false;
					for (int j = sz(lru) - 1; j >= 0; j--)
					{
						if (lru[j] == ans[0][i])
						{
							i0 = true;
						}
						else if (lru[j] == ans[1][i])
						{
							i1 = true;
						}
						else if (lru[j] == ans[2][i])
						{
							i2 = true;
						}

						if (i0 == true && i1 == true && i2 == false)
						{
							ans[2][i] = pages[i];
							lru.pb(pages[i]);
							break;
						}
						else if (i0 == true && i1 == false && i2 == true)
						{
							ans[1][i] = pages[i];
							lru.pb(pages[i]);
							break;
						}
						else if (i0 == false && i1 == true && i2 == true)
						{
							ans[0][i] = pages[i];
							lru.pb(pages[i]);
							break;
						}
					}
				}
			}
		}

		// for(auto v:ans){
		//     for(auto it:v){
		//         cout<<it<<" ";
		//     }cout<<endl;
		// }
		cout << "************** LRU Page Replcament Method *************\n"
			 << endl;
		// cout<<"-------------------------------------------------------"<<endl;
		for (int i = 0; i < 3; i++)
		{
			cout << "| Frame" << i + 1 << " ";
			for (int j = 0; j < ans[0].size(); j++)
			{
				cout << "|";
				cout << setw(3) << ans[i][j] << " ";
			}
			cout << "|";
			cout << endl;
		}

		// cout<<"-------------------------------------------------------"<<endl;
		cout << endl
			 << "Number Of pageFault : " << sz(pages) - hit << endl;
		cout << "Number of Hit : " << hit << "\n\n\n";
	}
	else
	{
		cout << "************** LRU Page Replcament Method *************\n"
			 << endl;
		// cout<<"-------------------------------------------------------"<<endl;
		for (int i = 0; i < 3; i++)
		{
			cout << "| Frame" << i + 1 << " ";
			for (int j = 0; j < ans[0].size(); j++)
			{
				cout << "|";
				cout << setw(3) << ans[i][j] << " ";
			}
			cout << "|";
			cout << endl;
		}
		cout << endl
			 << "Number Of pageFault : " << sz(pages) - hit << endl;
		cout << "Number of Hit : " << hit << "\n\n\n";
	}
}

void optimal_page_replacement(vector<int> pages)
{
	vector<vector<int>> ans(3, vector<int>(sz(pages), -1));

	bool flag, flag1;
	int hit = 0;
	vector<int> lru;
	if (sz(pages) >= 1)
	{
		ans[0][0] = pages[0];
		lru.pb(pages[0]);

		for (int i = 1; i < sz(pages); i++)
		{

			// copy prev page frames

			flag = false;
			for (int j = 0; j < 3; j++)
			{
				ans[j][i] = ans[j][i - 1];
			}

			for (int j = 0; j < 3; j++)
			{
				if (ans[j][i] == pages[i])
				{
					flag = true;
					hit++;
					lru.pb(pages[i]);
					break;
				}
			}

			if (!flag)
			{
				flag1 = false;
				for (int j = 0; j < 3; j++)
				{
					if (ans[j][i] == -1)
					{
						ans[j][i] = pages[i];
						lru.pb(pages[i]);
						flag1 = true;
						break;
					}
				}

				if (!flag1)
				{
					int ind0 = find(pages.begin() + i, pages.end(), ans[0][i]) - pages.begin();
					int ind1 = find(pages.begin() + i, pages.end(), ans[1][i]) - pages.begin();
					int ind2 = find(pages.begin() + i, pages.end(), ans[2][i]) - pages.begin();
					if (ind0 > ind1)
					{
						if (ind0 > ind2)
						{
							ans[0][i] = pages[i];
						}
						else
						{
							ans[2][i] = pages[i];
						}
					}
					else
					{
						if (ind1 > ind2)
						{
							ans[1][i] = pages[i];
						}
						else
						{
							ans[2][i] = pages[i];
						}
					}
				}
			}
		}

		// for(auto v:ans){
		//     for(auto it:v){
		//         cout<<it<<" ";
		//     }cout<<endl;
		// }
		cout << "************** Optimal Page Replcament Method *************\n"
			 << endl;
		// cout<<"-------------------------------------------------------"<<endl;
		for (int i = 0; i < 3; i++)
		{
			cout << "| Frame" << i + 1 << " ";
			for (int j = 0; j < ans[0].size(); j++)
			{
				cout << "|";
				cout << setw(3) << ans[i][j] << " ";
			}
			cout << "|";
			cout << endl;
		}

		// cout<<"-------------------------------------------------------"<<endl;
		cout << endl
			 << "Number Of pageFault : " << sz(pages) - hit << endl;
		cout << "Number of Hit : " << hit << "\n\n\n";
	}
	else
	{
		cout << "************** Optimal Page Replcament Method *************\n"
			 << endl;
		// cout<<"-------------------------------------------------------"<<endl;
		for (int i = 0; i < 3; i++)
		{
			cout << "| Frame" << i + 1 << " ";
			for (int j = 0; j < ans[0].size(); j++)
			{
				cout << "|";
				cout << setw(3) << ans[i][j] << " ";
			}
			cout << "|";
			cout << endl;
		}

		cout << endl
			 << "Number Of pageFault : " << endl;
		cout << "Number of Hit : "
			 << "\n\n\n";
	}
}
void FIFO(vector<int> pageTrace, int n)
{
	vector<vector<int>> v(3, vector<int>(n, -1));
	int pageFault = 0, hit = 0;
	int key = 1;

	v[2][0] = pageTrace[0];

	for (int i = 1; i < n; i++)
	{

		for (int j = 0; j < 3; j++)
		{
			v[j][i] = v[j][i - 1];
		}

		bool flag = false;
		for (int j = 0; j < 3; j++)
		{
			if (v[j][i] == pageTrace[i])
			{
				flag = true;
				break;
			}
		}

		if (!flag)
		{
			v[key][i] = pageTrace[i];
			key--;
			if (key == -1)
			{
				key = 2;
			}
		}
		else
		{
			hit++;
		}
	}
	cout << "************* FIFO Page Replcament Method *************\n"
		 << endl;
	// cout<<"-------------------------------------------------------"<<endl;
	for (int i = 2; i >= 0; i--)
	{
		if (i == 2)
			cout << "| Frame1"
				 << " ";
		else if (i == 1)
			cout << "| Frame2"
				 << " ";
		else
			cout << "| Frame3"
				 << " ";
		for (int j = 0; j < v[0].size(); j++)
		{
			cout << "|";
			cout << setw(3) << v[i][j] << " ";
		}
		cout << "|";
		cout << endl;
	}
	// cout<<"-------------------------------------------------------"<<endl;
	cout << endl
		 << "Number Of pageFault : " << n - hit << endl;
	cout << "Number of Hit : " << hit << "\n\n\n";
	// cout<<hit<<endl<<n-hit<<endl;
}

int main()
{
		vector<int> pageTrace;
		int n;
		cout<<"Enter Total number of page Trace : ";
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			pageTrace.push_back(x);
		}
		FIFO(pageTrace, n);
		LRU(pageTrace);
		optimal_page_replacement(pageTrace);

		int out = 0;
		cout<<"Enter Any key and enter to exit : ";
		cin>>out;
	return 0;
}
