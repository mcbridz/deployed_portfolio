let encoding_wheel = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()-_=+[{]}|;:'\"\\/,<.>? "

function get_good_index(index, arr) {
    if (index >= 0 && index < arr.length) {
        return index
    } else if (index < 0) {
        while (index < 0) {
            index += arr.length
        }
        return index
    }
    return index % arr.length
}
// localStorage.setItem("data", JSON.stringify(this.data))
function save_data(data, dest) {
    localStorage.setItem(dest, JSON.stringify(data))
}

let app = new Vue({
    el: '#app',
    data: {
        rotation: 0,
        plain_text: "",
        cypher_text: "",
        data: [],
    },
    created: function () {
        this.data = JSON.parse(localStorage.getItem("data"))
        if (this.data === null) {
            this.data = []
        }
    },
    methods: {
        encrypt_text: function () {
            this.rotation = parseInt(this.rotation)
            let output_text = ""
            let input_text = this.plain_text
            for (let i = 0; i < input_text.length; ++i) {
                let char_tmp = input_text[i]
                let shifted_index = encoding_wheel.indexOf(char_tmp)
                console.log("char_tmp", char_tmp, "shifted_index", shifted_index, "encoding wheel L", encoding_wheel.length)
                if (shifted_index != -1) {
                    shifted_index = (shifted_index + this.rotation)
                    shifted_index = get_good_index(shifted_index, encoding_wheel)
                    output_text += encoding_wheel[shifted_index]
                } else {
                    output_text += char_tmp
                }
            }
            this.cypher_text = output_text
        },
        decrypt_text: function () {
            this.rotation = parseInt(this.rotation)
            let output_text = ""
            let input_text = this.cypher_text
            for (let i = 0; i < input_text.length; ++i) {
                let char_tmp = input_text[i]
                let shifted_index = encoding_wheel.indexOf(char_tmp)
                console.log("char_tmp", char_tmp, "shifted_index", shifted_index, "encoding wheel L", encoding_wheel.length)
                if (shifted_index != -1) {
                    shifted_index = shifted_index - this.rotation
                    shifted_index = get_good_index(shifted_index, encoding_wheel)
                    output_text += encoding_wheel[shifted_index]
                } else {
                    output_text += char_tmp
                }
            }
            this.plain_text = output_text
        },
        clear_text: function () {
            this.plain_text = ""
            this.cypher_text = ""
        },
        save_text: function () {
            let tmp_data = { pt: this.plain_text, ct: this.cypher_text, rv: this.rotation }
            this.data.push(tmp_data)
            localStorage.setItem("data", JSON.stringify(this.data))
        },
        load: function (index) {
            this.plain_text = this.data[index].pt
            this.cypher_text = this.data[index].ct
            this.rotation = this.data[index].rv
        },
        delete_item: function (index) {
            this.data.splice(index, 1)
            save_data(this.data, "data")
        }
    }
})