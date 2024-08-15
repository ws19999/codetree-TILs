fun main()
{
    val n=readLine()!!.toInt()
    if(n>=90)print("passed")
    else
    {
        print("need ${90-n} more score")
    }
}