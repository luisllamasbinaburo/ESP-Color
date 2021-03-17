/***************************************************
Copyright (c) 2021 Luis Llamas
(www.luisllamas.es)

This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by
the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more details.

You should have received a copy of the GNU Affero General Public License along with this program.  If not, see <http://www.gnu.org/licenses
****************************************************/

#include <ESP_Color.h>


TFT_eSprite tftSprite = TFT_eSprite(&M5.Lcd);

void setup() {
	Serial.begin(115200);
	M5.begin();
	M5.Lcd.setRotation(0);

	tftSprite.setColorDepth(16);
	tftSprite.createSprite(M5.Lcd.width(), M5.Lcd.height());
	tftSprite.fillScreen(TFT_BLACK);
}


void loop()
{
	M5.update();

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

	tftSprite.fillScreen(color.ToRgb565());
	tftSprite.pushSprite(0, 0);
	delay(50000);
}


