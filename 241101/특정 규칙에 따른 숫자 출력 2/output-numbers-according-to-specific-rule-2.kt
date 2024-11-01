fun main()
{
    val n=readLine()!!.toInt()
    var num=9
    for(i in 1..n)
    {
        for(j in 1..n)
        {
            print("${num} ")
            num-=2
            if(num<0)num=9
        }
        print("\n")
    }
}