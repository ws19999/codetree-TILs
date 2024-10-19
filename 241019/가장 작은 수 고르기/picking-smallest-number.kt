import kotlin.math.min
fun main()
{
    val nums=readLine()!!.trim().split(" ").map{it.toInt()}
    var answer=1000
    for(i in 0..9)
    {
        answer=min(nums[i],answer)
    }
    print(answer)
}