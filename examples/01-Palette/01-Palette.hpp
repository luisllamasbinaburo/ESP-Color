/***************************************************
Copyright (c) 2020 Luis Llamas
(www.luisllamas.es)

This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by
the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more details.

You should have received a copy of the GNU Affero General Public License along with this program.  If not, see <http://www.gnu.org/licenses
****************************************************/

#include <ESP_Color.h>

TFT_eSprite tftSprite = TFT_eSprite(&M5.Lcd);

ESP_Color::Palette<uint16_t> palette(ESP_Color::Palettes64::MAGMA_64, 64);

void setup() {
	Serial.begin(115200);
	M5.begin();
	M5.Lcd.setRotation(0);

	tftSprite.setColorDepth(16);
	tftSprite.createSprite(M5.Lcd.width(), M5.Lcd.height());
	tftSprite.fillScreen(TFT_BLACK);
}

void Render()
{
	for(size_t h = 0; h < M5.Lcd.height(); h++)
	{
		auto index = (int)(64 * (float)h / M5.Lcd.height());
		tftSprite.drawFastHLine(0, h, M5.Lcd.width(), palette[index]);
	}
	
	tftSprite.pushSprite(0, 0);
}


void loop()
{
	M5.update();

	Render();
}