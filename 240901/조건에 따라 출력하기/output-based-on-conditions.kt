fun main()
{
    val n=readLine()!!.toInt()
    var finished=false
    for(i in 1..n)
    {
        val num=readLine()!!.toInt()
        if(finished)continue
        else if(num==0)finished=true
        else if(num%3==0)println(num/3)
        else println(num+2)
    }
}