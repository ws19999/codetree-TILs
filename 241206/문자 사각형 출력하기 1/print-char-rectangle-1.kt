fun main()
{
    val br=System.`in`.bufferedReader()
    val bw=System.`out`.bufferedWriter()
    val N=br.readLine()!!.toInt()
    var arr = Array (N){Array(N){""} }
    var c:Char = 'A'
    for(j in N-1 downTo 0)
    {
        for(i in N-1 downTo 0)
        {
            arr[i][j]=c.toString()
            c++
            if(c>'Z') c='A'
        }
    }
    for(i in 0..N-1)
    {
        for(j in 0..N-1)
        {
            bw.write("${arr[i][j]} ")
        }
        bw.write("\n")
    }
    bw.close()
}