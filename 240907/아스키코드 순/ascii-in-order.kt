fun main()
{
    val n=readLine()!!.toInt()
    val lists = mutableListOf<String>()
    for(i in 1..n)
    {
        val str=readLine()!!
        lists.add(str)
    }
    lists.sort()
    print(lists[0])
}