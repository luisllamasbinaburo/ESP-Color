# ESP-Color Library

ESP_Color contains library for colors conversion and operations using a MCU like ESP8266 or ESP32. It's replace the previous version 'Arduino-ColorConverter"

The class `ESP_Color::Color` include color formats RGB888, RGB666, RGB565, RGB332, HSV, HSL, greyscale GREY256, GREY16, GREY4 and black and white BW

Also, 'ESP_Color::Color' contains operations like addition or blending, and alpha channel management.

## Use example
```c++
ESP_Color::Color color(1.0f, 0.5f, 0.2f);

Serial.printf("R:%5.2f\tG:%5.2f\tB:%5.2f\tA:%5.2f\n", color.R, color.G, color.B, color.A);
Serial.printf("R:%d\tG:%d\tB:%d\tA:%d\n", color.R_Byte(), color.G_Byte(), color.B_Byte(), color.A_Byte());
Serial.println();

auto hsl = color.ToHsl();
Serial.printf("H:%5.2f\tS:%5.2f\tL:%5.2f\tA:%5.2f\n", hsl.H, hsl.S, hsl.L, hsl.A);

auto hsv = color.ToHsv();
Serial.printf("H:%5.2f\tS:%5.2f\tL:%5.2f\tA:%5.2f\n", hsv.H, hsv.S, hsv.V, hsv.A);

Serial.println();
Serial.printf("RGB8888\t:%x\n", color.ToRgba8888());
Serial.printf("RGB888 \t:%x\n", color.ToRgb888());
Serial.printf("RGB666 \t:%x\n", color.ToRgb666());
Serial.printf("RGB565 \t:%x\n", color.ToRgb565());

Serial.println();
Serial.printf("GREY256\t:%d\n", color.ToGray256());
Serial.printf("GREY16 \t:%d\n", color.ToGray16());
Serial.printf("GREY4  \t:%d\n", color.ToGray4());
Serial.printf("BW     \t:%d\n", color.ToBW());
```


## Color palettes

ESP_Color also includes `ESP_Color::Palette`, an color array designet to perform projects, user interfaces, or effects efficiently.

Some 64 colors predefined palettes are included.
```c++
ESP_Color::Palette<uint16_t> palette(ESP_Color::Palettes64::MAGMA_64, 64);

for(size_t h = 0; h < screen.height(); h++)
{
	auto index = (int)(64 * (float)h / screen.height());
	screen.drawFastHLine(0, h, screen.width(), palette[index]);
}
```

It's also posible to generate your palette, with an arbitrary number of elements, using the method `generate`
```c++
ESP_Color::Palette<uint16_t> palette(128);

const ESP_Color::Color color1((uint16_t)TFT_YELLOW);
const ESP_Color::Color color2((uint16_t)TFT_CYAN);
const ESP_Color::Color color3((uint16_t)TFT_RED);

palette.Generate([color1, color2, color3](float f) -> uint16_t { 
	return ESP_Color::Color::FromGradient(color1, color2, color3, f).ToRgb565();
} );
```
