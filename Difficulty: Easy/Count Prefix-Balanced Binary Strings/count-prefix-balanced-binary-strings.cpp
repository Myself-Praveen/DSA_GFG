class Solution {
	
	public:
	int prefixStrings(int N)
	{
		// Your code goes here
		long long int t[N + 1];
		t[0] = 1;
		t[1] = 1;
		int mod = 1000000007;
		for (int i = 2; i <= N; i++)
			{
			t[i] = 0;
			for (int j = 0; j<i; j++)
				{
				t[i] = (t[i] + (t[j] * t[i - j-1])) % mod;
			}
		}
		return t[N]%mod;
	}
	
};
