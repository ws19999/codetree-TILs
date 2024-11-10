fun main()
{
    val br=System.`in`.bufferedReader()
    val bw=System.`out`.bufferedWriter()
    val N=br.readLine().toInt()
    var arr=Array(N+1){IntArray(N+1){0} }
    for(i in 1..N)
    {
        for(j in 1..i)
        {
            if(j==1 || j==i)arr[i][j]=2
            else
            {
                arr[i][j]=arr[i-1][j-1]+arr[i-1][j]
            }
            bw.write("${arr[i][j]} ")
        }
        bw.write("\n")
    }
    bw.close()
}