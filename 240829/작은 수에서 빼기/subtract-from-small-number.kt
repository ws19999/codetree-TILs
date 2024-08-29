fun main()
{
    val (a,b)=readLine()!!.split(" ").map{it.toInt()}
    if(a<b)print(a-b)
    else print(b-a)
}