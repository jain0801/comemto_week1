void    dik_roop(char arr[1000][1000], int visit[1000][1000], int f_short[1000][1000], int i, int j)
{
    visit[i][j] = 1;
    printf("%d %d\n", i, j);
    if (arr[i + 1][j] == 'E')
    {
        if (arr[i][j] + 1 < f_short[i + 1][j])
        {
            f_short[i + 1][j] = arr[i][j] + 1;
            return ;
        }
    }
    if (arr[i][j + 1] == 'E')
    {
        if (arr[i][j] + 1 < f_short[i][j + 1])
        {
            f_short[i][j + 1] = arr[i][j] + 1;
            return ;
        }
    }
    if (arr[i + 1][j] == 'O' && visit[i + 1][j] == 0)
    {
        if (arr[i][j] + 1 < f_short[i + 1][j])
        {
            f_short[i + 1][j] = arr[i][j] + 1;
            dik_roop(arr, visit, f_short, i + 1, j);
        }
    }
    if (arr[i][j + 1] == 'O' && visit[i][j + 1] == 0)
    {
        if (arr[i][j] + 1 < f_short[i][j + 1])
        {
            f_short[i][j + 1] = arr[i][j] + 1;
            dik_roop(arr, visit, f_short, i, j + 1);
        }
    }
}

int dik_alg(char arr[][1000])
{
    int f_short[1000][1000];
    int visit[1000][1000];
    
    //visit[0][0] = 1;
    f_short[0][0] = 0;
    printf("check");
    for (int i = 0; i < 1000; i++){
        for (int j = 0; j < 1000; j++){
            
            f_short[i][j] = 5000;
        }
    }
    printf("check");
    //dik_roop(arr, visit, f_short, 0, 0);
    //E까지 갈 수 있으면 E까지의 최소 경로값 반환
    if (f_short[999][999] != 0)
        return 1;
    return 1;
        
}

int main()
{
    char arr[1000][1000];
    int result;
    
    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            if (j == 0)
                arr[i][j] = 'O';
            else if (i == 999)
                arr[i][j] = 'O';
            else
                arr[i][j] = 'X';
        }
    }
    //printf("check");
    arr[0][0] = 'S';
    arr[999][999] = 'E';
    // for (int i = 0; i < 30; i++)
    // {
    //     for (int j = 0; j < 30; j++)
    //     {
    //         printf("%c", arr[i][j]);
    //     }
    //     printf("\n");
    // }
    printf("check");
    result = dik_alg(arr);
    printf("%c", result);
    return 0;
}
