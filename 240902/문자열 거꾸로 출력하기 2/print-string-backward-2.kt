fun main()
{
    val n=readLine()!!.toInt()
    for (i in 1..n)
    {
        val str=readLine()!!
        val len=str.length
        for(j in len-1 downTo 0)
        {
            print(str[j])
        }
        print("\n")
    }
}