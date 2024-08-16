fun main()
{
    val a=readLine()!!.toDouble()
    val b=readLine()!!.toDouble()
    if(a>=1.0 && b>=1.0)print("H")
    else if(a>=0.5 && b>=0.5)print("M")
    else print("L")
}