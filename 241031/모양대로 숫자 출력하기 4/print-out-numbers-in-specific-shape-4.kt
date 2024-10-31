fun main()
{
    val n=readLine()!!.toInt()
    var num=0
    for(i in n downTo 1)
    {
        for(j in 1..n-i)print("  ")
        for(j in 1..i)
        {
            num=num%8+2
            print("${num} ")
        }
        print("\n")
    }
}