fun main()
{
    val (a,b,c)=readLine()!!.split(" ").map{it.toInt()}
    if(b>a && b>c)print("1 ")
    else print("0")
    if(a==b && b==c)print("1")
    else print("0")
}