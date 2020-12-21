input.onButtonPressed(Button.A, function () {
    wuKong.mecanumRun(wuKong.RunList.left)
})
input.onGesture(Gesture.ScreenDown, function () {
    wuKong.mecanumRun(wuKong.RunList.stop)
})
input.onButtonPressed(Button.AB, function () {
    wuKong.mecanumRun(wuKong.RunList.Front)
})
input.onButtonPressed(Button.B, function () {
    wuKong.mecanumRun(wuKong.RunList.right)
})
wuKong.mecanumWheel(
wuKong.ServoList.S1,
wuKong.ServoList.S2,
wuKong.ServoList.S3,
wuKong.ServoList.S4
)
