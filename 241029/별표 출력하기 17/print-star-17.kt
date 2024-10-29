fun main()
{
    val n=readLine()!!.toInt()
    for(i in 1..n)
    {
        for(j in 1..i)print("*")
        print("\n")
    }
    for(i in n-1 downTo 1)
    {
        for(j in 1..i)print("*")
        print("\n")
    }
}