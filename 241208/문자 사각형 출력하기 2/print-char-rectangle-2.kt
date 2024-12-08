fun main()
{
    val N=readLine()!!.toInt()
    var arr = Array(N){Array(N){""}}
    var c='A'
    for(j in 0..N-1)
    {
        if(j%2==0)
        {
            for(i in 0..N-1)
            {
                arr[i][j]=c.toString()
                c++
                if(c>'Z')c='A'
            }
        }
        else
        {
            for(i in N-1 downTo 0)
            {
                arr[i][j]=c.toString()
                c++
                if(c>'Z')c='A'
            }
        }
    }
    for(i in 0..N-1)
    {
        for(j in 0..N-1)
        {
            print("${arr[i][j]} ")
        }
        println()
    }
}