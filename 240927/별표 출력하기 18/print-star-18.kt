fun main()
{
    val n=readLine()!!.toInt()
    for (i in n-1 downTo 0)
    {
        for(j in 1..2*i)print("  ")
        for(j in 1..2*(n-1-i))print("* ")
        println("*")
    }
}