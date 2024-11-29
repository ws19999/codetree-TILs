fun main()
{
    val (a,b)=readLine()!!.split(" ")
    when
    {
        a.length<b.length -> print("$a ${a.length}")
        b.length<a.length -> print("$b ${b.length}")
        else -> print("equal")
    }
}