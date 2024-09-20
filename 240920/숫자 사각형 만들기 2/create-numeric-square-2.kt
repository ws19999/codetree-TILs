fun main()
{
    val (n,m)=readLine()!!.split(" ").map{it.toInt()}
    var num=n*m
    for(i in 1..n)
    {
        for(j in 1..m)
        {
            print("${num} ")
            num--
        }
        print("\n")
    }
}