fun main()
{
    val n=readLine()!!.toInt()
    for(i in 1..n)
    {
        var c=readLine()!!
        if(c[0]>= '0' && c[0]<='9')println(c[0].code)
        else println(c[0])
    }
}