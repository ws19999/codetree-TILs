fun main()
{
    val n=readLine()!!.toInt()
    val m=readLine()!!.toInt()
    println(n*(m%10))
    println(n*((m/10)%10))
    println(n*(m/100))
    println(n*m)
}