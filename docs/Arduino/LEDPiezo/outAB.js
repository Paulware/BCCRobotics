input.onButtonPressed(Button.A, function () {
    serial.writeLine("A")
    basic.showIcon(IconNames.Yes)
})
input.onButtonPressed(Button.B, function () {
    serial.writeLine("B")
    basic.showIcon(IconNames.No)
})
serial.redirect(
SerialPin.P8,
SerialPin.P12,
BaudRate.BaudRate115200
)
basic.showIcon(IconNames.Heart)
basic.forever(function () {
})
