fun main()
{
    val (a,b,c) = readLine()!!.split(" ").map{it.toInt()}
    println("sum = ${a+b+c}")
    println("mul = ${a*b*c}")
}