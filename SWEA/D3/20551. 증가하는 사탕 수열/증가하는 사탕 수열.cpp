#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int arr[3];
        int count = 0;
        cin >> arr[0] >> arr[1] >> arr[2];
        if(arr[2] < 3) {
            cout << '#' << test_case << ' ' << -1 << '\n';
            continue;
        }
        for(int j=2; j>0; j--) {
        	if(arr[j]<=arr[j-1]) {
            	count += arr[j-1]-(arr[j]-1);
                arr[j-1] = (arr[j]-1);
       		}
            if(arr[j-1]<=0) {
                count=-1;
                break;
            }
        }
        cout << '#' << test_case << ' ' << count << '\n';
    }
	return 0;
}