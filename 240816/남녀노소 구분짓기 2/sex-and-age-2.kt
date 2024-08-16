fun main()
{
    val sex=readLine()!!.toInt()
    val age=readLine()!!.toInt()
    if(sex==0)
    {
        if(age<19)print("B")
        else print("M")
    }
    else
    {
        if(age<19)print("G")
        else print("W")
    }
}