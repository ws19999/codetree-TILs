fun main()
{
    val (x,y,z) = readLine()!!.split(" ").map{it.toInt()}
    println("avg "+(x+y+z)/3)
    print("sum "+(x+y+z))
}