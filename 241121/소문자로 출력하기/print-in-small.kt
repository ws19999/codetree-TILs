fun main()
{
    val str=readLine()!!
    for(i in str)
    {
        val a=i.lowercaseChar()
        if(a<='z' && a>='a')print(a)
    }
}