fun main()
{
    val n=readLine()!!.toInt()
    for(i in n downTo 1)
    {
        for(j in 1..i*2)print("*")
        print("\n")
    }
    for(i in 2..n)
    {
        for(j in 1..i*2)print("*")
        print("\n")
    }
}