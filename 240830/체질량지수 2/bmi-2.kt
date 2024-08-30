fun main()
{
    val (cm,kg)=readLine()!!.split(" ").map{it.toInt()}
    val m=cm.toDouble()/100
    println(String.format("%.0f",kg/(m*m)))
    if(kg/(m*m)>=25)print("Obesity")
}