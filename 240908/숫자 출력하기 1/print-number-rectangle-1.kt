fun main()
{
    val (n,m) = readLine()!!.split(" ").map{it.toInt()}
    var num=0
    for(i in 1..n)
    {
        for(j in 1..m)
        {
            print("${++num} ")
        }
        print("\n")
    }
}