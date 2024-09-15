fun main()
{
    val n=readLine()!!.toInt()
    var answer=0
    for(i in 1..n)
    {
        val num=readLine()!!.toInt()
        answer+=num
    }
    var ans=answer.toDouble()/n
    println(String.format("%.1f",ans))
    if(ans<70)print("fail")
}