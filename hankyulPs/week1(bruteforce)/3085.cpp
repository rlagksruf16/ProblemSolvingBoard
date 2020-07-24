#include "iostream"

using namespace std;

int n = 0;
int max_Candy = 0;
char arr[51][51];

void Horizontal() // 가로 방향 이어진 캔디 계산
{
	for (int i = 0; i < n; i++)
	{
		int count = 1;
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == arr[i][j + 1]) // 같은 캔디수 만큼 카운트 증가
			{
				count++;
			}
			else 
			{
				if (max_Candy < count) // 최댓값 갱신
				{
					max_Candy = count;
				}
				count = 1; // 카운트 초기화
			}
		}
	}
}

void Vertical()
{
	for (int i = 0; i < n; i++) // 세로 방향 이어진 캔디 계산
	{
		int count = 1;
		for (int j = 0; j < n; j++)
		{
			if (arr[j][i] == arr[j + 1][i]) // 같은 캔디수 만큼 카운트 증가
			{
				count++;
			}
			else
			{
				if (max_Candy < count) // 최댓값 갱신
				{
					max_Candy = count;
				}
				count = 1; // 카운트 초기화
			}
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}


	for (int i = 0; i < n; i++)  // 세로 교환
	{
		for (int j = 0; j < n - 1; j++)
		{
			char tmp = arr[i][j];      // 세로 캔디 스왑
			arr[i][j] = arr[i][j + 1]; 
			arr[i][j + 1] = tmp;		
			
			Vertical();				   // 이어진 캔디수 검사
			Horizontal();

			tmp = arr[i][j];		   // 스왑 원위치
			arr[i][j] = arr[i][j + 1];
			arr[i][j + 1] = tmp;
		}
	}

	for (int i = 0; i < n; i++)  // 가로 교환
	{
		for (int j = 0; j < n - 1; j++)
		{
			char tmp = arr[j][i];	 //가로 캔디 스왑
			arr[j][i] = arr[j+1][i];
			arr[j+1][i] = tmp;

			Vertical();		         // 이어진 캔디수 검사
			Horizontal();

			tmp = arr[j][i];		 // 스왑 원위치
			arr[j][i] = arr[j+1][i];
			arr[j+1][i] = tmp;
		}
	}

	cout << max_Candy << endl;
}