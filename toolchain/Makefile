image:
	docker build --force-rm=true -t ricejasonf/parmexpr .

run:
	docker run --rm -it ricejasonf/parmexpr

push:
	docker push ricejasonf/parmexpr

vanilla_image:
	docker build --force-rm=true -f ./Dockerfile-vanilla \
															 -t ricejasonf/parmexpr-vanilla .
vanilla_run:
	docker run--rm -it ricejasonf/parmexpr-vanilla

vanilla_push:
	docker push ricejasonf/parmexpr-vanilla

emscripten_image:
	docker build --force-rm=true -f ./Dockerfile-emscripten \
															 -t ricejasonf/parmexpr-emscripten .
emscripten_run:
	docker run--rm -it ricejasonf/parmexpr-emscripten

emscripten_push:
	docker push ricejasonf/parmexpr-emscripten
