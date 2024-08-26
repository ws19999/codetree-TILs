fun main()
{
    var a=readLine()!!.toInt()
    var answer=0
    while(a>0)
    {
        answer+=a
        a--
    }
    print(answer)
}