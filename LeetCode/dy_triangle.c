//三角形最小路径和   https://leetcode-cn.com/problems/triangle/
//倒着来
#define min(a,b) ((a)<(b)?(a):(b))

int minimumTotal(int** triangle, int triangleSize, int* triangleColSize){
    for(int i=triangleSize-2;i>=0;i--)
    {
        for(int j=0;j<*(triangleColSize+i);j++)
        {
            triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);
        }
    }
    return triangle[0][0];
}


