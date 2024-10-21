fun main()
{
    val (n,m)=readLine()!!.trim().split(" ").map{it.toInt()}
    for(i in 1..n)
    {
        for(j in 0..m-1)
        {
            print("${j*n+i} ")
        }
        print("\n")
    }
}