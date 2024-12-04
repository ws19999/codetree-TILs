fun main()
{
    val (N,M,K)=readLine()!!.split(" ").map{it.toInt()}
    var arr=Array(N){""}
    for(i in 0..N-1)
    {
        arr[i]=readLine()!!
        for(tc in 1..K)
        {
            for(j in 0..M-1)
            {
                for(a in 1..K)print("${arr[i][j]}")
            }
            println()
        }
    }
}