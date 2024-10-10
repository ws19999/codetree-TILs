fun main()
{
    var num=0
    for(i in 1..3)
    {
        val str=readLine()!!
        num+=str.length
    }
    print(num)
}