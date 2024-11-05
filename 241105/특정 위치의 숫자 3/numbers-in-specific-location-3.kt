fun main()
{
    val n=readLine()!!.toInt()
    val nums=readLine()!!.trim().split(" ").map{it.toInt()}.toIntArray()
    print("${nums[2]+nums[4]+nums[7]-nums[6]}")
}