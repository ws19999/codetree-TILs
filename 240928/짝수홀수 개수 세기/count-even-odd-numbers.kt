fun main()
{
    val n=readLine()!!.toInt()
    var 짝수=0
    var 홀수=0
    var zero=false
    for(i in 1..n)
    {
        val num=readLine()!!.toInt()
        if(zero)continue
        if(num==0)
        {
            zero=true
            continue
        }
        if(num%2==0)짝수++
        else 홀수++
    }
    println(짝수)
    println(홀수)
}