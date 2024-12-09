fun main()
{
    val n=readLine()!!.toInt()
    for(i in 0..n-1)
    {
        for(j in 1..(n * n) - ((n - i) * (n - i)))print(" ")
        for(j in 1..(n - i) * (n - i))print("*")
        println()
    }
}