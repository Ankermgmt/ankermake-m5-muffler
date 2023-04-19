USB_ADDRESS ?= $(error USB_ADDRESS is not set)

.PHONY: all clean build upload dashboard logs

all: build upload dashboard logs

clean:
	esphome clean config.yaml
build:
	esphome config config.yaml
	esphome compile config.yaml
upload:
	@echo "Uploading to $(USB_ADDRESS)"
	esphome upload --device $(USB_ADDRESS) config.yaml
logs:
	@echo "Uploading to $(USB_ADDRESS)"
	esphome logs config.yaml --device $(USB_ADDRESS)
dashboard:
	esphome dashboard . --open-ui --address 127.0.0.1 --port 6053
run:
	esphome \
		-s name ankermake-m5-muffler \
		-s friendly_name "AnkerMake M5 Muffler" \
		-s ntc_resistance "100kOhm" \
		run config.yaml --device $(USB_ADDRESS)