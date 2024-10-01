fun main()
{
    val n=readLine()!!.toInt()
    val lists=readLine()!!.trim().split(" ").map{it.toInt()}
    for(i in n-1 downTo 0)
    {
        print("${lists[i]} ")
    }
}