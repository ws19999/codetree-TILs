fun main()
{
    val n=readLine()!!.toInt()
    for(i in 1..n)
    {
        for(j in 1..i)print("@ ")
        print("\n")
    }
    for (j in 1..n-1)
    {
        for(k in 1..j)print("  ")
        for(k in 1..n-j)print("@ ")
        print("\n")
    }

}