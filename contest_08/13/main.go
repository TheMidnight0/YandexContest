type PepperoniRecipe struct {
	PizzaIngredients
}

func (r *PepperoniRecipe) newPizza() PizzaRecipe {
	r.dough = ""
	r.sauces = nil
	r.toppings = nil
	r.cheeses = nil
	return r
}

func (r *PepperoniRecipe) makeBase() PizzaRecipe {
	r.dough = "PepperoniDough"
	return r
}
func (r *PepperoniRecipe) makeFilling() PizzaRecipe {
	r.sauces = append(r.sauces, "Tomato paste")
	r.toppings = append(r.toppings, "Pepperoni", "Garlic")
	r.cheeses = append(r.cheeses, "Mozzarella", "Fontina")
	return r
}
func (r *PepperoniRecipe) Bake() Pizza {
	return NewPizza(r.dough, r.sauces, r.toppings, r.cheeses)
}
func (r *PepperoniRecipe) setDough(dough string) PizzaRecipe {
	return r
}
func (r *PepperoniRecipe) addSauce(sauce string) PizzaRecipe {
	return r
}
func (r *PepperoniRecipe) addTopping(topping string) PizzaRecipe {
	return r
}
func (r *PepperoniRecipe) addCheese(cheese string) PizzaRecipe {
	return r
}

type HawaiianRecipe struct {
	PizzaIngredients
}

func (r *HawaiianRecipe) newPizza() PizzaRecipe {
	r.dough = ""
	r.sauces = nil
	r.toppings = nil
	r.cheeses = nil
	return r
}

func (r *HawaiianRecipe) makeBase() PizzaRecipe {
	r.dough = "HawaiianDough"
	return r
}
func (r *HawaiianRecipe) makeFilling() PizzaRecipe {
	r.sauces = append(r.sauces, "Tomato paste")
	r.toppings = append(r.toppings, "Pineapple", "Onion", "Bacon")
	r.cheeses = append(r.cheeses, "Mozzarella")
	return r
}
func (r *HawaiianRecipe) Bake() Pizza {
	return NewPizza(r.dough, r.sauces, r.toppings, r.cheeses)
}
func (r *HawaiianRecipe) setDough(dough string) PizzaRecipe {
	return r
}
func (r *HawaiianRecipe) addSauce(sauce string) PizzaRecipe {
	return r
}
func (r *HawaiianRecipe) addTopping(topping string) PizzaRecipe {
	return r
}
func (r *HawaiianRecipe) addCheese(cheese string) PizzaRecipe {
	return r
}