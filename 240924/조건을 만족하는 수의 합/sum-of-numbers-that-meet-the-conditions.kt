fun main()
{
    val n=readLine()!!.toInt()
    var answer=0
    for(i in n..500)
    {
        if(i%2==0)answer+=i
    }
    print(answer)
}