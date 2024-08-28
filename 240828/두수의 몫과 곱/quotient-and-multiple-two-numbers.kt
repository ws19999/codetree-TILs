fun main()
{
    val (a,b) = readLine()!!.split(" ").map{it.toInt()}
    println("$a / $b = ${a/b}")
    println("$a * $b = ${a*b}")
}