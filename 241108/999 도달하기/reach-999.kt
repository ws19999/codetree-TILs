fun main()
{
    val n=readLine()!!.toInt()
    var a=1
    var b=n
    print("${a} ${b} ")
    while(true)
    {
        var c=a+b
        print("${c} ")
        if(c>999)break
        a=b
        b=c
    }
}