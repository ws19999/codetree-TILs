fun main()
{
    var num=readLine()!!
    var nums=num.toInt()
    var len=num.length
    var answer=0
    while(nums>0)
    {
        answer+=nums%10
        nums/=10
    }
    for(i in len-1 downTo 0)print(num[i])
    print(" ${answer}")
}